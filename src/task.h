#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>

// Enum for task priority levels
enum class Priority {
    LOW,
    MEDIUM,
    HIGH
};

// Abstract base class for all tasks
class Task {
protected:
    int id;
    std::string title;
    std::string description;
    Priority priority;
    bool completed;
    std::string deadline;

public:
    // Constructor
    Task(int id, std::string title, std::string description, 
         Priority priority, std::string deadline);
    
    // Virtual destructor for proper cleanup of derived classes
    virtual ~Task() = default;
    
    // Pure virtual function - must be implemented by derived classes
    virtual void display() const = 0;
    virtual std::string getType() const = 0;
    
    // Getters
    int getId() const { return id; }
    std::string getTitle() const { return title; }
    Priority getPriority() const { return priority; }
    bool isCompleted() const { return completed; }
    
    // Setters
    void setTitle(const std::string& newTitle) { title = newTitle; }
    void markComplete() { completed = true; }
    
    // Utility function
    std::string priorityToString() const;
};

// Derived class for work-related tasks
class WorkTask : public Task {
private:
    std::string projectName;
    
public:
    WorkTask(int id, std::string title, std::string description,
             Priority priority, std::string deadline, std::string project);
    
    void display() const override;
    std::string getType() const override { return "Work"; }
    std::string getProject() const { return projectName; }
};

// Derived class for personal tasks
class PersonalTask : public Task {
private:
    std::string category;
    
public:
    PersonalTask(int id, std::string title, std::string description,
                 Priority priority, std::string deadline, std::string cat);
    
    void display() const override;
    std::string getType() const override { return "Personal"; }
    std::string getCategory() const { return category; }
};

#endif