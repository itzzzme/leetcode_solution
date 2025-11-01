class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode temp(0, head);
        unordered_set<int> mp{nums.begin(), nums.end()};

        for (ListNode* curr = &temp; curr->next != nullptr;)
            if (mp.contains(curr->next->val))
                curr->next = curr->next->next;
            else
                curr = curr->next;

        return temp.next;
    }
};