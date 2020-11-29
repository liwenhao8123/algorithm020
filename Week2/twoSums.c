/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//UT_hash_handle
//HASH_FIND_INT
//HASH_ADD_INT

struct hashTable {
    int key;
    int val;
    UT_hash_handle hh;
};

struct hashTable* hashtable;

struct hashTable* find(int ikey) {
    struct hashTable* tmp;
    HASH_FIND_INT(hashtable, &ikey, tmp);
    return tmp;
}

void insert(int ikey, int ival) {
    struct hashTable* it = find(ikey);
    if (it == NULL) {
        struct hashTable* tmp = malloc(sizeof(struct hashTable));
        tmp->key = ikey, tmp->val = ival;
        HASH_ADD_INT(hashtable, key, tmp);
    } else {
        it->val = ival;
    }
}

//引入hashmap，时间复杂度降低到O(n)
//uthash 是C的比较优秀的开源代码，它实现了常见的hash操作函数，例如查找、插入、删除等
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    hashtable = NULL;
    for (int i = 0; i < numsSize; i++){
        struct hashTable * it = find(target - nums[i]);
        if (it != NULL){
            int * ret = (int *)malloc(sizeof(int) * 2);
            ret[1] = i;
            ret[0] = it->val;
            *returnSize = 2;
            return ret;
        }
        insert(nums[i], i);
    }
    return NULL;
}