bool isValid(char * s){
    char *stack;
    int i, j = 0, k = 0;
    int sum = 0;

    stack = malloc(strlen(s));
    memset(stack, 0, strlen(s));
    for(i=0; i<strlen(s); i++) {
        switch(s[i]) {
        case '(':
        case '{':
        case '[':
            stack[j] = s[i];
            j++;
            break;
        case ')':
        case ']':
        case '}':
            j--;
            if (j<0) {
                return false;
            }
            if ( (stack[j] == '(' && s[i] != ')') ||
                 (stack[j] == '[' && s[i] != ']') ||
                 (stack[j] == '{' && s[i] != '}') ) {
                return false;
            }
            break;
        default:
            break;
        }
    }
    if (j != 0) {
        return false;
    } else {
        return true;
    }
}
