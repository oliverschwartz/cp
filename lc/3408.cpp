class TaskManager {
    using ptu_t = std::tuple<int, int, int>;
    using pu_t = std::tuple<int, int>; 
    unordered_map<int, pu_t> _task_map; 
    priority_queue<ptu_t> _task_heap; 

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& t : tasks)
        {
            add(t[0], t[1], t[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        _task_map[taskId] = make_tuple(priority, userId);
        _task_heap.push(make_tuple(priority, taskId, userId));
    }
    
    void edit(int taskId, int newPriority) {
        int user_id = std::get<1>(_task_map[taskId]);
        add(user_id, taskId, newPriority);
    }
    
    void rmv(int taskId) {
        _task_map.erase(taskId);
    }
    
    int execTop() {
        while (_task_heap.size())
        {
            ptu_t ptu = _task_heap.top();
            
            // check if in map and priority and user matches
            auto it = _task_map.find(std::get<1>(ptu));
            if (it != _task_map.end() && std::get<0>(it->second) == std::get<0>(ptu) && std::get<1>(it->second) == std::get<2>(ptu))
            {
                _task_heap.pop();
                _task_map.erase(std::get<1>(ptu));
                return std::get<2>(ptu);
            }

            _task_heap.pop();
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */
