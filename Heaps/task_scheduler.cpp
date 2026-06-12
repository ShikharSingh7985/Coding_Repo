/*
Intuition:

We are given tasks and a cooldown period p.

Same tasks must have at least p intervals between them.

Example:
tasks = ['A','A','A','B','B','B']
p = 2

One valid order:
A B idle A B idle A B

Main idea:

The task with highest frequency should be done first.

Why?
Because the most frequent task creates the most cooldown restrictions.
If we delay it too much, we may need more idle time later.

So we use a max heap.

Steps:

1. Count frequency of every task.
2. Push all frequencies into max heap.
3. In one cycle, we can execute at most p + 1 different tasks.
   Because after doing one task, the same task can be repeated only after p gaps.
4. Pop up to p + 1 highest frequency tasks.
5. Decrease their frequency by 1 because one instance is completed.
6. Push remaining frequencies back into heap.
7. If heap is empty, add only actual tasks done to time.
8. Otherwise, add full cycle length p + 1 to time.

Time Complexity: O(n log 26), approximately O(n)
Space Complexity: O(26), approximately O(1)
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int p) {

        // n stores total number of tasks
        int n = tasks.size();

        // mp stores frequency of each task
        unordered_map<char, int> mp;
        
        // Count frequency of each task
        for(char &ch : tasks) {
            mp[ch]++;
        }

        // Max heap stores task frequencies
        priority_queue<int> pq;

        /*
        We want to finish the task with highest frequency first,
        so that it does not remain at the end and create extra idle time.
        */

        // time stores minimum intervals needed
        int time = 0;
        
        // Push all task frequencies into max heap
        for(auto &it : mp) {
            pq.push(it.second);
        }
        
        // Continue until all tasks are completed
        while(!pq.empty()) {

            // temp stores remaining frequencies after one cycle
            vector<int> temp;

            /*
            One cycle length is p + 1.

            In one cycle, we try to execute p + 1 different tasks.
            This helps maintain cooldown between same tasks.
            */
            for(int i = 1; i <= p + 1; i++) {

                // If heap has tasks available
                if(!pq.empty()) {

                    // Complete one instance of the highest frequency task
                    temp.push_back(pq.top() - 1);

                    // Remove it from heap
                    pq.pop();
                }
            }
            
            // Push unfinished tasks back into heap
            for(int &freq : temp) {

                // If frequency is still greater than 0,
                // this task has remaining instances
                if(freq > 0)
                    pq.push(freq);
            }
            
            // If heap is empty, all tasks are finished
            if(pq.empty()) {

                // Add only the actual tasks done in the last cycle
                time += temp.size();
            }

            else {

                // Heap is not empty, so full cycle is needed
                // including possible idle slots
                time += (p + 1);
            }
        }
        
        // Return minimum total time
        return time;
    }
};