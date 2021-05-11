class Solution {
public:
    string interpret(string command) {
        string parse = "";
        for(int i = 0; i < command.length(); ++i){
            if(command[i] == 'G'){
                parse += 'G';
            }
            else{
                if(command[i] == '(' ){
                    if(command[i+1] == ')'){
                        parse += 'o';
                        i += 1;
                    }
                    else{
                        parse += "al";
                        i += 3;
                    }
                }
            }
        }
        return parse;
    }
};