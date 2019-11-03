/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int power(int x, int y) {
    int i;
    int ret = 1;

    for (i=0; i<y; i++) {
        ret *= x;
    }
    return ret;
}

int value(struct ListNode* node) {
    int ret;
    int num = 0;
    struct ListNode* tmpnode = node;

    while (tmpnode != NULL) {
        ret += node->val * power(10, num);
        node = node->next;
        tmpnode = node;
        num++;
    }
    return ret;
}

int digitsnum(int value) {
    int ret = 0;
    int tmpvalue = value;

    while(tmpvalue != 0) {
        tmpvalue /= 10;
        ret++;
    }
    return ret;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int value1, value2, sum, listsize, tmp;
    struct ListNode* l3;
    int i;

    value1 = value(l1);
    value2 = value(l2);
    sum = value1 + value2;
    listsize = digitsnum(sum);
    l3 = malloc(sizeof(struct ListNode) * listsize);
    for(i=0; i<listsize; i++) {
        l3[listsize - i -1].val = sum / power(10, listsize - i -1);
        sum = sum % 10;
    }
    for(i=0; i<listsize-1; i++) {
        l3[i].next = &l3[i+1];
    }
    l3[listsize-1].next = NULL;

    return l3;
}
