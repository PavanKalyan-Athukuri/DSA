class Node{
    Node child[];
    boolean isEnd;
    Node(){
        this.child = new Node[26];
        this.isEnd = false;
    }
    public boolean isEnd(){
        return this.isEnd;
    }
    public void setEnd(){
        this.isEnd = true;
    }
    public boolean containsKey(char ch){
        return this.child[ch-'a']!=null;
    }
    public Node get(char ch){
        return this.child[ch-'a'];
    }
    public void put(char ch,Node node){
        this.child[ch-'a'] = node;
    }
}
class MagicDictionary {
    Node root;
    public MagicDictionary() {
        this.root = new Node();
    }
    
    public void buildDict(String[] dictionary) {
        for(int i=0;i<dictionary.length;i++){
            Node temp = this.root;
            for(char ch:dictionary[i].toCharArray()){
                if(!temp.containsKey(ch))
                    temp.put(ch,new Node());
                temp = temp.get(ch);
            }
            temp.setEnd();
        }
    }
    
    public boolean search(String searchWord) {
       Node temp = this.root;
       return helper(searchWord,temp,0,0);
    }
    public boolean helper(String word,Node temp,int index,int count){
        if(temp==null||count>1)
        return false;
        if(index==word.length())
        return temp.isEnd()&&count==1;
        for(int i=0;i<26;i++){
            if(helper(word,temp.child[i],index+1,(word.charAt(index)-'a'!=i)?count+1:count))
            return true;
        }
        return false;
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dictionary);
 * boolean param_2 = obj.search(searchWord);
 */