CC = g++

LIB=libopencv-clang

PROJECT_SRC_DIR = $(LIB)/src
PROJECT_TEST_DIR = $(LIB)/tests
PROJECT_INCLUDE_DIR = $(PROJECT_SRC_DIR)/include

CFLAGS = -std=c++11 -Wall -Werror -ferror-limit=1 -I$(PROJECT_SRC_DIR)
CFLAGS += $(shell pkg-config --cflags --libs opencv4)

BUILD_DIR = build
UNAME_S = $(shell uname -s)
ARCH = $(shell uname -m)
LIB_EXTENSION = so
PLATFORM = linux
VERSION = $(shell pkg-config --modversion opencv4)
ifeq ($(UNAME_S),Darwin)
	PLATFORM = macos
	LIB_EXTENSION = dylib
endif
LIB_DEF = $(LIB).$(VERSION)
LIBNAME = $(LIB_DEF).$(PLATFORM).$(ARCH).$(LIB_EXTENSION)
LIB_FILE = $(BUILD_DIR)/lib/$(LIBNAME)
LIB_BINARY_ARCHIVE_NAME = $(LIBNAME).tar.gz
LIB_SOURCES_ARCHIVE_NAME = libcv-c-api.src.tar.gz
JAVA_SOURCES_DIR = $(BUILD_DIR)/src/main/java

MAVEN_FLAGS = -Dversion=$(VERSION) -Dlib=libcv
MAVEN_DEPLOY_FLAGS = --batch-mode deploy -DgroupId=clang -DartifactId=opencv.$(package) -Dpackaging=jar
MAVEN_DEPLOY_FLAGS += -DrepositoryId=github -Durl=https://maven.pkg.github.com/c-to-java-api/$(LIB) $(MAVEN_FLAGS)


LIB_INCLUDE_DIR = $(BUILD_DIR)/include
LIB_BUILD_DIR = $(BUILD_DIR)/lib
TEST_BINARIES_ROOT = $(BUILD_DIR)/tests

all: lib

pre:
	$(shell rm -fr $(BUILD_DIR))
	$(shell mkdir -p $(LIB_INCLUDE_DIR))
	$(shell mkdir -p $(LIB_BUILD_DIR))

	$(shell cp $(PROJECT_INCLUDE_DIR)/* $(LIB_INCLUDE_DIR)/)


lib: clean pre
	$(CC) $(CFLAGS) -dynamiclib $(PROJECT_SRC_DIR)/*.cpp -o $(LIB_FILE) -current_version $(VERSION) -compatibility_version $(VERSION)

java-src:
	jextract --source -t clang.opencv.$(package) -I $(PROJECT_SRC_DIR) --header-class-name $(package) --output $(JAVA_SOURCES_DIR) $(args) $(PROJECT_INCLUDE_DIR)/capi.h

jar: java-src
	mvn clean package $(MAVEN_FLAGS).$(package)

archive-sources:
	$(shell tar -zcvf $(BUILD_DIR)/$(LIB_SOURCES_ARCHIVE_NAME) $(PROJECT_SRC_DIR) Makefile pom.xml)

archive-lib: lib
	$(shell tar -zcvf $(BUILD_DIR)/$(LIB_BINARY_ARCHIVE_NAME) $(LIB_INCLUDE_DIR) $(LIB_BUILD_DIR))

archive: jar archive-sources archive-lib

deploy-jar: pre
	mvn $(MAVEN_DEPLOY_FLAGS)

clean:
	rm -fr $(BUILD_DIR)
	mvn clean $(MAVEN_FLAGS)

.PHONY: test-suite
test-suite:
	$(shell mkdir -p $(TEST_BINARIES_ROOT))
	$(CC) $(CFLAGS) -Lbuild/lib $(LIB_BUILD_DIR)/$(LIBNAME) $(suite) -o $(TEST_BINARIES_ROOT)/test.binary

	./$(TEST_BINARIES_ROOT)/test.binary $(args)

test: clean lib
	$(MAKE) test-suite suite=$(PROJECT_TEST_DIR)/test_mat.cpp
