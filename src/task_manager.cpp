#include "task_manager.h"

TaskManager::TaskManager() : nextId(1) {}

void TaskManager::addWorkTask(std::string title, std::string description,
                              Priority priority, std::string deadline, 
                              std::string project) {
    tasks.push_back(std::make_unique<WorkTask>(
        nextId++, title, description, priority, deadline, project
    ));
    std::cout << "✓ Work task added successfully!" << std::endl;
}

void TaskManager::addPersonalTask(std::string title, std::string description,
                                  Priority priority, std::string deadline,
                                  std::string category) {
    tasks.push_back(std::make_unique<PersonalTask>(
        nextId++, title, description, priority, deadline, category
    ));
    std::cout << "✓ Personal task added successfully!" << std::endl;
}

void TaskManager::removeTask(int id) {
    auto it = std::remove_if(tasks.begin(), tasks.end(),
        [id](const std::unique_ptr<Task>& task) {
            return task->getId() == id;
        });
    
    if (it != tasks.end()) {
        tasks.erase(it, tasks.end());
        std::cout << "✓ Task #" << id << " removed successfully!" << std::endl;
    } else {
        std::cout << "✗ Task #" << id << " not found!" << std::endl;
    }
}

void TaskManager::markTaskComplete(int id) {
    Task* task = findTaskById(id);
    if (task) {
        task->markComplete();
        std::cout << "✓ Task #" << id << " marked as complete!" << std::endl;
    } else {
        std::cout << "✗ Task #" << id << " not found!" << std::endl;
    }
}

void TaskManager::displayAllTasks() const {
    if (tasks.empty()) {
        std::cout << "\nNo tasks available." << std::endl;
        return;
    }
    
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "  ALL TASKS (" << tasks.size() << " total)" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    for (const auto& task : tasks) {
        task->display();
    }
}

void TaskManager::displayPendingTasks() const {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "  PENDING TASKS" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    bool found = false;
    for (const auto& task : tasks) {
        if (!task->isCompleted()) {
            task->display();
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "\nNo pending tasks!" << std::endl;
    }
}

void TaskManager::displayCompletedTasks() const {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "  COMPLETED TASKS" << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    
    bool found = false;
    for (const auto& task : tasks) {
        if (task->isCompleted()) {
            task->display();
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "\nNo completed tasks yet!" << std::endl;
    }
}

void TaskManager::displayTasksByPriority(Priority priority) const {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << "  TASKS - Priority: ";
    
    switch(priority) {
        case Priority::HIGH:   std::cout << "HIGH"; break;
        case Priority::MEDIUM: std::cout << "MEDIUM"; break;
        case Priority::LOW:    std::cout << "LOW"; break;
    }
    
    std::cout << std::endl << std::string(60, '=') << std::endl;
    
    bool found = false;
    for (const auto& task : tasks) {
        if (task->getPriority() == priority) {
            task->display();
            found = true;
        }
    }
    
    if (!found) {
        std::cout << "\nNo tasks with this priority!" << std::endl;
    }
}

int TaskManager::getCompletedCount() const {
    return std::count_if(tasks.begin(), tasks.end(),
        [](const std::unique_ptr<Task>& task) {
            return task->isCompleted();
        });
}

int TaskManager::getPendingCount() const {
    return std::count_if(tasks.begin(), tasks.end(),
        [](const std::unique_ptr<Task>& task) {
            return !task->isCompleted();
        });
}

Task* TaskManager::findTaskById(int id) {
    auto it = std::find_if(tasks.begin(), tasks.end(),
        [id](const std::unique_ptr<Task>& task) {
            return task->getId() == id;
        });
    
    return (it != tasks.end()) ? it->get() : nullptr;
}