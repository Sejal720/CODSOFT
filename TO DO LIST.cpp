/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class TodoList {
private:
    vector<pair<string, bool>> tasks;

public:
    void addTask(const string& task) {
        tasks.push_back(make_pair(task, false));
        cout << "Task added: " << task << endl;
    }

    void deleteTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            cout << "Task deleted: " << tasks[index].first << endl;
            tasks.erase(tasks.begin() + index);
        } else {
            cout << "Invalid index. No task deleted." << endl;
        }
    }

    void markAsCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].second = true;
            cout << "Task marked as completed: " << tasks[index].first << endl;
        } else {
            cout << "Invalid index. No task marked as completed." << endl;
        }
    }

    void displayTasks() {
        if (tasks.empty()) {
            cout << "No tasks in the to-do list." << endl;
        } else {
            cout << "To-Do List:" << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i].first;
                if (tasks[i].second) {
                    cout << " (Completed)";
                } else {
                    cout << " (Pending)";
                }
                cout << endl;
            }
        }
    }
};

int main() {
    TodoList todoList;
    int choice;

    do {
        cout << "\n1. Add Task\n2. Delete Task\n3. Mark as Completed\n4. Display Tasks\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string task;
                cout << "Enter the task: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, task);
                todoList.addTask(task);
                break;
            }
            case 2: {
                int index;
                cout << "Enter the index of the task to delete: ";
                cin >> index;
                todoList.deleteTask(index - 1); // Adjust for 1-based indexing
                break;
            }
            case 3: {
                int index;
                cout << "Enter the index of the task to mark as completed: ";
                cin >> index;
                todoList.markAsCompleted(index - 1); // Adjust for 1-based indexing
                break;
            }
            case 4:
                todoList.displayTasks();
                break;
            case 0:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
