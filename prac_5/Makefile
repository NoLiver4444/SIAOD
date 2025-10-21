# Компилятор и флаги
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20 -pedantic-errors
LDFLAGS = -lgtest -lgtest_main -lpthread

# Директории
SRC_DIR = src
AVL_TREE_DIR = $(SRC_DIR)/AVL_Tree
ITERATOR_DIR = $(SRC_DIR)/Iterator
MODEL_DIR = $(SRC_DIR)/model
TEST_DIR = tests
OBJ_DIR = obj
GCOV_DIR = obj/gcov
TESTS_OBJ_DIR = obj/tests
REPORT_DIR = report
BIN_DIR = bin

# Цели
TARGET = test
MAIN_TARGET = main_program
GCOV_TARGET = gcov_report

# Исходные файлы
SRCS = $(wildcard $(AVL_TREE_DIR)/*.cpp) \
       $(wildcard $(ITERATOR_DIR)/*.cpp) \
       $(wildcard $(MODEL_DIR)/*.cpp)

OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Главный файл
MAIN_SRC = $(SRC_DIR)/main.cpp
MAIN_OBJ = $(OBJ_DIR)/main.o

# Тестовые файлы
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp,$(TESTS_OBJ_DIR)/%.o,$(TEST_SRCS))

# Фильтруем объектные файлы без main
LIB_OBJS = $(filter-out $(MAIN_OBJ),$(OBJS))

.PHONY: all test main gcov_report clean rebuild style leaks valgrind answ run test_run install_lib install_gtest help

all: main test

main: $(MAIN_TARGET)

test: $(TARGET)

# Компиляция основной программы
$(MAIN_TARGET): $(BIN_DIR) $(LIB_OBJS) $(MAIN_OBJ)
	$(CXX) $(CXXFLAGS) $(LIB_OBJS) $(MAIN_OBJ) -o $(BIN_DIR)/$@
	@echo "\n\033[0;32mMain program compiled successfully!\033[0m\n"
	@echo "Run with: ./$(BIN_DIR)/$(MAIN_TARGET)"

# Запуск основной программы
run: $(MAIN_TARGET)
	@echo "\n\033[0;32mRunning main program...\033[0m\n"
	@./$(BIN_DIR)/$(MAIN_TARGET)

# Установка зависимостей
install_lib:
	sudo apt update
	sudo apt install gcc lcov valgrind

install_gtest:
	sudo apt install libgtest-dev cmake
	sudo cmake -S /usr/src/googletest -B /usr/src/googletest/build
	sudo cmake --build /usr/src/googletest/build
	sudo cp -r /usr/src/googletest/googletest/include/gtest /usr/local/include/
	sudo cp /usr/src/googletest/build/lib/*.a /usr/local/lib/

# Gcov отчет
gcov_report: $(GCOV_DIR) $(TESTS_OBJ_DIR) $(BIN_DIR)
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage $(TEST_SRCS) $(SRCS) -o $(BIN_DIR)/$(GCOV_TARGET) $(LDFLAGS) -lgcov
	@./$(BIN_DIR)/$(GCOV_TARGET)
	lcov --ignore-errors mismatch --capture --directory . --output-file coverage.info
	lcov --remove coverage.info "/usr/*" "tests/*" --output-file coverage.info.cleaned
	genhtml coverage.info.cleaned --output-directory coverage
	@echo "\n\033[0;32mGcov report generated in coverage/ directory\033[0m\n"

# Компиляция тестов
$(TARGET): $(TESTS_OBJ_DIR) $(OBJ_DIR) $(TEST_OBJS) $(LIB_OBJS) $(BIN_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_OBJS) $(LIB_OBJS) $(LDFLAGS) -o $(BIN_DIR)/$@
	@echo "\n\033[0;32mTests compiled successfully!\033[0m\n"
	@echo "Run with: make test_run"

# Запуск тестов
test_run: $(TARGET)
	@echo "\n\033[0;32mRunning tests...\033[0m\n"
	@./$(BIN_DIR)/$(TARGET)

# Компиляция объектных файлов для src
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Компиляция объектных файлов для поддиректорий src
$(OBJ_DIR)/AVL_Tree/%.o: $(AVL_TREE_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/Iterator/%.o: $(ITERATOR_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/model/%.o: $(MODEL_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Компиляция объектных файлов для тестов
$(TESTS_OBJ_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Компиляция объектных файлов для gcov
$(GCOV_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage -c $< -o $@

$(GCOV_DIR)/AVL_Tree/%.o: $(AVL_TREE_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage -c $< -o $@

$(GCOV_DIR)/Iterator/%.o: $(ITERATOR_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage -c $< -o $@

$(GCOV_DIR)/model/%.o: $(MODEL_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -fprofile-arcs -ftest-coverage -c $< -o $@

# Создание директорий
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) $(OBJ_DIR)/AVL_Tree $(OBJ_DIR)/Iterator $(OBJ_DIR)/model

$(TESTS_OBJ_DIR):
	@mkdir -p $(TESTS_OBJ_DIR)

$(GCOV_DIR):
	@mkdir -p $(GCOV_DIR) $(GCOV_DIR)/AVL_Tree $(GCOV_DIR)/Iterator $(GCOV_DIR)/model

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Очистка
clean:
	rm -rf $(OBJ_DIR) $(REPORT_DIR) $(GCOV_DIR) $(TESTS_OBJ_DIR) $(BIN_DIR)
	rm -f *.a *.o *.gcno *.gcda *.gcov coverage.info
	rm -f $(TARGET) $(GCOV_TARGET) $(MAIN_TARGET)
	rm -rf coverage
	rm -f coverage.info.cleaned
	rm -f answ/*.bin
	rm -f answ/*.txt
	@echo "\n\033[0;32mClean completed!\033[0m\n"

rebuild: clean all

# Проверка стиля кода
clang:
	cp ../materials/.clang-format ./.clang-format
	clang-format -n --style=file $$(find . -type f \( -name "*.tpp" -o -name "*.h" -o -name "*.cpp" \))
	rm -f .clang-format

clang-fix:
	cp ../materials/.clang-format ./.clang-format
	clang-format -i --style=file $$(find . -type f \( -name "*.tpp" -o -name "*.h" -o -name "*.cpp" \))
	rm -f .clang-format

# Проверка утечек памяти
leaks: $(TARGET)
	leaks --atExit -- ./$(BIN_DIR)/$(TARGET)

valgrind: $(TARGET)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(BIN_DIR)/$(TARGET)

# Создание директории для ответов
answ:
	mkdir -p answ

# Справка
help:
	@echo "Available commands:"
	@echo "  make all       - Build both main program and tests"
	@echo "  make main      - Build only main program"
	@echo "  make run       - Build and run main program"
	@echo "  make test      - Build only tests"
	@echo "  make test_run  - Build and run tests"
	@echo "  make gcov_report - Generate code coverage report"
	@echo "  make clean     - Clean all build artifacts"
	@echo "  make rebuild   - Clean and rebuild everything"
	@echo "  make style     - Check code style"
	@echo "  make style-fix - Fix code style automatically"
	@echo "  make leaks     - Run tests with leaks detection"
	@echo "  make valgrind  - Run tests with valgrind"
	@echo "  make install_lib - Install required libraries"
	@echo "  make install_gtest - Install Google Test framework"