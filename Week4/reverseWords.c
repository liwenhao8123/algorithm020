char * reverseWords(char * s){
    int length = strlen(s);
    int i = 0;
    while ( i < length ){
        int start = i;
        while ( i < length && s[i] != ' '){
            i++;
        }
        int left = start;
        int right = i - 1;
        while (left < right){
            int tmp = s[right];
            s[right--] = s[left];
            s[left++] = tmp;
        }
        while ( i < length && s[i] == ' '){
            i++;
        }
    }
    return s;
}