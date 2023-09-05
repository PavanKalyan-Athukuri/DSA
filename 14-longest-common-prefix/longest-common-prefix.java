class Node{
    Node link[];
    int cp;
    boolean flag;
    Node(){
        this.link = new Node[26];
        this.cp = 0;
        this.flag = false;
    }
    public boolean isExists(char ch){
        return this.link[ch-'a']!=null;
    }
    public void put(char ch,Node node){
        this.link[ch-'a'] = node;
    }
    public Node get(char ch){
        return this.link[ch-'a'];
    }
    public void increasePrefix(){
        this.cp = this.cp+1;
    }
    public void setEnd(){
        this.flag = true;
    }
    public boolean isEnd(){
        return this.flag;
    }
}
class Trie{
    Node root;
    Trie(){
        this.root = new Node();
    }
    public void insert(String str){
        Node temp = this.root;
        for(int i=0;i<str.length();i++){
            if(!temp.isExists(str.charAt(i))){
                temp.put(str.charAt(i),new Node());
            }
            temp = temp.get(str.charAt(i));
            temp.increasePrefix();
        }
        temp.setEnd();
    }
    public String search(String str,int length){
        Node temp = root;
        for(int i=0;i<str.length();i++){
            if(temp.link[str.charAt(i)-'a']!=null){
                System.out.println(temp.get(str.charAt(i)).cp);
                if(temp.get(str.charAt(i)).cp==length){
                    temp = temp.get(str.charAt(i));
                }
                else{
                    return str.substring(0,i);
                }
            }
        }
        return str;
    }
}
class Solution {
    public String longestCommonPrefix(String[] strs) {
        Trie trie = new Trie();
        for(int i=0;i<strs.length;i++){
            trie.insert(strs[i]);
        }
        return trie.search(strs[0],strs.length);
    }
}