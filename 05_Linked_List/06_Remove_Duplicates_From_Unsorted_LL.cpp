// Simple approach using unordered map.
// we are first storing the head value in map and then checking for the value of next node in the map.
// if it is present then we are updating the next of current node.
// if not found then we are updating the curent node.

class Solution{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node* removeDuplicates(Node *head){
        unordered_map<int, int> mp;
        mp[head->data]++;
        Node* temp = head;
        while(temp->next != NULL){
            if(mp.find(temp->next->data) != mp.end()){
                temp->next = temp->next->next;
            }
            else{
                temp = temp->next;
                mp[temp->data]++;
            }
        }
        return head;
    }
};



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using 2 loops
    TC: O(n^2)
    SC: O(1)
*/
void removeDuplicates(struct Node* start)
{
    struct Node* ptr1, * ptr2, * dup;
    ptr1 = start;

    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL)
    {
        ptr2 = ptr1;

        /* Compare the picked element with rest
           of the elements */
        while (ptr2->next != NULL)
        {
            /* If duplicate then delete it */
            if (ptr1->data == ptr2->next->data)
            {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                delete(dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
}
