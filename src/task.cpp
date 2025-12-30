#include "task.h"
#include <iomanip>

// Task base class constructor
Task::Task(int id, std::string title, std::string description,
           Priority priority, std::string deadline)
    : id(id), title(title), description(description),
      priority(priority), completed(false), deadline(deadline) {}

// Convert priority enum to string
std::string Task::priorityToString() const {
    switch(priority) {
        case Priority::HIGH:   return "HIGH";
        case Priority::MEDIUM: return "MEDIUM";
        case Priority::LOW:    return "LOW";
        default:               return "UNKNOWN";
    }
}

// WorkTask constructor
WorkTask::WorkTask(int id, std::string title, std::string description,
                   Priority priority, std::string deadline, std::string project)
    : Task(id, title, description, priority, deadline), 
      projectName(project) {}

// Display work task details
void WorkTask::display() const {
    std::cout << "\n[WORK TASK #" << id << "]" << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Project: " << projectName << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Priority: " << priorityToString() << std::endl;
    std::cout << "Deadline: " << deadline << std::endl;
    std::cout << "Status: " << (completed ? "COMPLETED" : "PENDING") << std::endl;
}

// PersonalTask constructor
PersonalTask::PersonalTask(int id, std::string title, std::string description,
                           Priority priority, std::string deadline, std::string cat)
    : Task(id, title, description, priority, deadline),
      category(cat) {}

// Display personal task details
void PersonalTask::display() const {
    std::cout << "\n[PERSONAL TASK #" << id << "]" << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Category: " << category << std::endl;
    std::cout << "Description: " << description << std::endl;
    std::cout << "Priority: " << priorityToString() << std::endl;
    std::cout << "Deadline: " << deadline << std::endl;
    std::cout << "Status: " << (completed ? "COMPLETED" : "PENDING") << std::endl;
}