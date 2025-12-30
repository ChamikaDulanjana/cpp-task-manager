#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include "task.h"
#include <vector>
#include <memory>
#include <algorithm>

// TaskManager class - manages collection of tasks
class TaskManager {
private:
    std::vector<std::unique_ptr<Task>> tasks;
    int nextId;
    
public:
    TaskManager();
    ~TaskManager() = default;
    
    // Task operations
    void addWorkTask(std::string title, std::string description,
                     Priority priority, std::string deadline, std::string project);
    void addPersonalTask(std::string title, std::string description,
                         Priority priority, std::string deadline, std::string category);
    void removeTask(int id);
    void markTaskComplete(int id);
    
    // Display operations
    void displayAllTasks() const;
    void displayPendingTasks() const;
    void displayCompletedTasks() const;
    void displayTasksByPriority(Priority priority) const;
    
    // Statistics
    int getTotalTasks() const { return tasks.size(); }
    int getCompletedCount() const;
    int getPendingCount() const;
    
    // Utility
    Task* findTaskById(int id);
};

#endif // TASK_MANAGER_H