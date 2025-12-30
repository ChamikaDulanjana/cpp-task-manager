#include "task_manager.h"
#include <iostream>
#include <string>

void displayHeader() {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "        C++ TASK MANAGER SYSTEM v1.0" << std::endl;
    std::cout << "    CSP3341 - Programming Languages Assignment" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
}

void displayMenu() {
    std::cout << "\n--- MAIN MENU ---" << std::endl;
    std::cout << "1. Add Work Task" << std::endl;
    std::cout << "2. Add Personal Task" << std::endl;
    std::cout << "3. View All Tasks" << std::endl;
    std::cout << "4. View Pending Tasks" << std::endl;
    std::cout << "5. View Completed Tasks" << std::endl;
    std::cout << "6. Mark Task as Complete" << std::endl;
    std::cout << "7. Delete Task" << std::endl;
    std::cout << "8. View Statistics" << std::endl;
    std::cout << "9. Demo Mode (Auto-populate)" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "\nEnter choice: ";
}

void demoMode(TaskManager& manager) {
    std::cout << "\n[DEMO MODE] Creating sample tasks..." << std::endl;
    
    // Add sample work tasks
    manager.addWorkTask("Complete API Documentation", 
                       "Write comprehensive API docs for REST endpoints",
                       Priority::HIGH, "2024-12-31", "Backend Development");
    
    manager.addWorkTask("Code Review", 
                       "Review pull requests from team members",
                       Priority::MEDIUM, "2024-12-25", "Team Management");
    
    manager.addWorkTask("Database Optimization",
                       "Optimize slow queries in production database",
                       Priority::HIGH, "2024-12-28", "Database Team");
    
    // Add sample personal tasks
    manager.addPersonalTask("Grocery Shopping",
                           "Buy vegetables, milk, and bread",
                           Priority::MEDIUM, "2024-12-24", "Household");
    
    manager.addPersonalTask("Gym Workout",
                           "Complete 45-minute cardio session",
                           Priority::LOW, "2024-12-26", "Health");
    
    manager.addPersonalTask("Study C++ Concepts",
                           "Review smart pointers and RAII principles",
                           Priority::HIGH, "2024-12-27", "Education");
    
    // Mark some as complete
    manager.markTaskComplete(2);
    manager.markTaskComplete(5);
    
    std::cout << "\n✓ Demo tasks created successfully!" << std::endl;
    std::cout << "  - 6 tasks added (3 work, 3 personal)" << std::endl;
    std::cout << "  - 2 tasks marked as complete" << std::endl;
}

void displayStatistics(const TaskManager& manager) {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "  TASK STATISTICS" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    int total = manager.getTotalTasks();
    int completed = manager.getCompletedCount();
    int pending = manager.getPendingCount();
    
    std::cout << "\nTotal Tasks: " << total << std::endl;
    std::cout << "Completed: " << completed;
    if (total > 0) {
        std::cout << " (" << (completed * 100 / total) << "%)";
    }
    std::cout << std::endl;
    
    std::cout << "Pending: " << pending;
    if (total > 0) {
        std::cout << " (" << (pending * 100 / total) << "%)";
    }
    std::cout << std::endl;
}

int main() {
    TaskManager manager;
    displayHeader();
    
    std::cout << "\n✓ Task Manager initialized successfully!" << std::endl;
    std::cout << "✓ System ready to manage your tasks" << std::endl;
    
    int choice;
    bool running = true;
    
    while (running) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore(); // Clear newline from buffer
        
        switch(choice) {
            case 1: {
                std::string title, desc, deadline, project;
                int priorityChoice;
                
                std::cout << "\nEnter task title: ";
                std::getline(std::cin, title);
                std::cout << "Enter description: ";
                std::getline(std::cin, desc);
                std::cout << "Enter deadline (YYYY-MM-DD): ";
                std::getline(std::cin, deadline);
                std::cout << "Enter project name: ";
                std::getline(std::cin, project);
                std::cout << "Priority (1=LOW, 2=MEDIUM, 3=HIGH): ";
                std::cin >> priorityChoice;
                std::cin.ignore();
                
                Priority p = (priorityChoice == 3) ? Priority::HIGH :
                            (priorityChoice == 2) ? Priority::MEDIUM : Priority::LOW;
                
                manager.addWorkTask(title, desc, p, deadline, project);
                break;
            }
            
            case 2: {
                std::string title, desc, deadline, category;
                int priorityChoice;
                
                std::cout << "\nEnter task title: ";
                std::getline(std::cin, title);
                std::cout << "Enter description: ";
                std::getline(std::cin, desc);
                std::cout << "Enter deadline (YYYY-MM-DD): ";
                std::getline(std::cin, deadline);
                std::cout << "Enter category: ";
                std::getline(std::cin, category);
                std::cout << "Priority (1=LOW, 2=MEDIUM, 3=HIGH): ";
                std::cin >> priorityChoice;
                std::cin.ignore();
                
                Priority p = (priorityChoice == 3) ? Priority::HIGH :
                            (priorityChoice == 2) ? Priority::MEDIUM : Priority::LOW;
                
                manager.addPersonalTask(title, desc, p, deadline, category);
                break;
            }
            
            case 3:
                manager.displayAllTasks();
                break;
                
            case 4:
                manager.displayPendingTasks();
                break;
                
            case 5:
                manager.displayCompletedTasks();
                break;
                
            case 6: {
                int id;
                std::cout << "\nEnter task ID to mark complete: ";
                std::cin >> id;
                std::cin.ignore();
                manager.markTaskComplete(id);
                break;
            }
            
            case 7: {
                int id;
                std::cout << "\nEnter task ID to delete: ";
                std::cin >> id;
                std::cin.ignore();
                manager.removeTask(id);
                break;
            }
            
            case 8:
                displayStatistics(manager);
                break;
                
            case 9:
                demoMode(manager);
                break;
                
            case 0:
                std::cout << "\n✓ Saving and exiting..." << std::endl;
                std::cout << "Thank you for using Task Manager!" << std::endl;
                running = false;
                break;
                
            default:
                std::cout << "\n✗ Invalid choice! Please try again." << std::endl;
        }
    }
    
    return 0;
}