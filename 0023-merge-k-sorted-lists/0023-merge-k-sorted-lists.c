struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(!list1) return list2;
    if(!list2) return list1;
    if(list1->val<list2->val){
        list1->next = mergeTwoLists(list1->next,list2);
        return list1;
    }
    else{
        list2->next = mergeTwoLists(list1,list2->next);
        return list2;
    }
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize == 1) return lists[0];
    if(listsSize == 0) return NULL;
    int i,j;
    for(i=0,j=listsSize-1;i<j;i++,j--){
        lists[i] = mergeTwoLists(lists[i],lists[j]);
        listsSize--;
    }
    return mergeKLists(lists,listsSize);
}
