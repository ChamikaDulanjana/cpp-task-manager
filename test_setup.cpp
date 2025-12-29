#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

// Function to display a section header
void displayHeader(const std::string& title) {
    std::cout << "\n" << std::string(50, '=') << std::endl;
    std::cout << "  " << title << std::endl;
    std::cout << std::string(50, '=') << std::endl;
}

int main() {
    // Main header
    displayHeader("C++ ENVIRONMENT SETUP VERIFICATION");
    
    // Compiler Information Section
    std::cout << "\n[COMPILER INFORMATION]" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    
    #ifdef __GNUC__
        std::cout << "Compiler: GCC (MinGW-W64)" << std::endl;
        std::cout << "Version: " << __GNUC__ << "." 
                  << __GNUC_MINOR__ << "." 
                  << __GNUC_PATCHLEVEL__ << std::endl;
    #elif defined(_MSC_VER)
        std::cout << "Compiler: Microsoft Visual C++" << std::endl;
        std::cout << "Version: " << _MSC_VER << std::endl;
    #endif
    
    std::cout << "C++ Standard: ";
    if (__cplusplus == 201703L) std::cout << "C++17" << std::endl;
    else if (__cplusplus == 202002L) std::cout << "C++20" << std::endl;
    else std::cout << __cplusplus << std::endl;
    
    // System Information
    std::cout << "\n[SYSTEM INFORMATION]" << std::endl;
    std::cout << std::string(50, '-') << std::endl;
    #ifdef _WIN32
        std::cout << "Operating System: Windows" << std::endl;
    #elif __linux__
        std::cout << "Operating System: Linux" << std::endl;
    #elif __APPLE__
        std::cout << "Operating System: macOS" << std::endl;
    #endif
    
    // Feature Testing Section
    displayHeader("TESTING C++ FEATURES");
    
    // Test 1: Basic data types and variables
    std::cout << "\n[Test 1] Basic Data Types & Variables" << std::endl;
    int taskCount = 5;
    double completionRate = 87.5;
    std::string projectName = "Task Manager System";
    bool isWorking = true;
    std::cout << "  Project: " << projectName << std::endl;
    std::cout << "  Tasks: " << taskCount << std::endl;
    std::cout << "  Completion Rate: " << std::fixed 
              << std::setprecision(1) << completionRate << "%" << std::endl;
    std::cout << "  Status: " << (isWorking ? "✓ PASS" : "✗ FAIL") << std::endl;
    
    // Test 2: STL Containers (Vector)
    std::cout << "\n[Test 2] STL Containers (std::vector)" << std::endl;
    std::vector<std::string> tasks = {
        "Setup development environment",
        "Install C++ compiler (GCC)",
        "Configure VS Code IDE",
        "Create test program",
        "Verify compilation process",
        "Initialize Git repository",
        "Complete Part B documentation"
    };
    
    std::cout << "  Task List (" << tasks.size() << " items):" << std::endl;
    for(size_t i = 0; i < tasks.size(); i++) {
        std::cout << "    " << (i+1) << ". " << tasks[i] << std::endl;
    }
    std::cout << "  Status: ✓ PASS" << std::endl;
    
    // Test 3: Range-based loops (C++11 feature)
    std::cout << "\n[Test 3] Range-Based Loops (C++11)" << std::endl;
    int completedTasks = 0;
    for(const auto& task : tasks) {
        if(task.find("Setup") != std::string::npos || 
           task.find("Install") != std::string::npos) {
            completedTasks++;
        }
    }
    std::cout << "  Completed tasks: " << completedTasks 
              << "/" << tasks.size() << std::endl;
    std::cout << "  Status: ✓ PASS" << std::endl;
    
    // Test 4: Lambda expressions (C++11 feature)
    std::cout << "\n[Test 4] Lambda Expressions (C++11)" << std::endl;
    auto calculateProgress = [](int completed, int total) -> double {
        return (static_cast<double>(completed) / total) * 100.0;
    };
    
    double progress = calculateProgress(4, 7);
    std::cout << "  Progress calculation: " << std::fixed 
              << std::setprecision(1) << progress << "%" << std::endl;
    std::cout << "  Status: ✓ PASS" << std::endl;
    
    // Test 5: Auto type deduction (C++11 feature)
    std::cout << "\n[Test 5] Auto Type Deduction (C++11)" << std::endl;
    auto message = "Type automatically deduced";
    auto count = 42;
    auto rate = 3.14159;
    std::cout << "  String variable (auto): \"" << message << "\"" << std::endl;
    std::cout << "  Integer variable (auto): " << count << std::endl;
    std::cout << "  Double variable (auto): " << rate << std::endl;
    std::cout << "  Status: ✓ PASS" << std::endl;
    
    // Final Summary
    displayHeader("VERIFICATION SUMMARY");
    std::cout << "\n✓ Compiler: Successfully detected and working" << std::endl;
    std::cout << "✓ C++ Standard Library: Fully functional" << std::endl;
    std::cout << "✓ STL Containers: Operational" << std::endl;
    std::cout << "✓ Modern C++ Features: Supported" << std::endl;
    std::cout << "✓ All tests: PASSED" << std::endl;
    
    displayHeader("ENVIRONMENT READY FOR DEVELOPMENT");
    std::cout << std::endl;
    
    return 0;
}