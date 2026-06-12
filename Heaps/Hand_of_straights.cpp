/*
Intuition:

We are given cards in hand and we need to divide them into groups
of size groupSize.

Each group must contain consecutive cards.

Example:
hand = [1,2,3,6,2,3,4,7,8]
groupSize = 3

Possible groups:
[1,2,3]
[2,3,4]
[6,7,8]

Main idea:

Always start making a group from the smallest available card.

Why smallest?

Because the smallest card cannot be placed after any smaller card.
So it must be the starting card of some group.

We use:
1. unordered_map to store frequency of each card.
2. min heap to always get the smallest available card.

Steps:

1. If total cards are not divisible by groupSize, return false.
2. Count frequency of all cards.
3. Push all unique cards into min heap.
4. Take the smallest card as start.
5. Try to form:
   start, start + 1, start + 2, ... start + groupSize - 1
6. Decrease frequency of each card.
7. If any needed card is missing, return false.
8. If frequency of a card becomes 0, it must be the smallest card
   currently in heap, then pop it.
9. If all groups are formed, return true.

Time Complexity: O(n log n)
Space Complexity: O(n)
*/

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        // n stores total number of cards
        int n = hand.size();

        // If cards cannot be equally divided into groups,
        // answer is false
        if (n % groupSize != 0) return false;

        // mp stores frequency of each card
        unordered_map<int, int> mp;

        // Min heap stores unique cards in increasing order
        priority_queue<int, vector<int>, greater<int>> pq;

        // Count frequency of every card
        for (int card : hand) {
            mp[card]++;
        }

        // Push all unique cards into min heap
        for (auto it : mp) {
            pq.push(it.first);
        }

        // Continue until all cards are used
        while (!pq.empty()) {

            // Always start group from smallest available card
            int start = pq.top();

            // Try to form consecutive group:
            // start, start+1, start+2, ... start+groupSize-1
            for (int card = start; card < start + groupSize; card++) {

                // If required card is not available,
                // group cannot be formed
                if (mp[card] == 0) {
                    return false;
                }

                // Use one occurrence of this card
                mp[card]--;

                // If this card frequency becomes 0,
                // remove it from heap
                if (mp[card] == 0) {

                    /*
                    Important:
                    If card frequency becomes 0,
                    then this card must be at top of heap.

                    If it is not at top, it means some smaller card
                    is still unused, so grouping is invalid.
                    */
                    if (pq.top() != card) {
                        return false;
                    }

                    // Remove exhausted card from heap
                    pq.pop();
                }
            }
        }

        // All cards successfully grouped
        return true;
    }
};