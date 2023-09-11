class Node{
    Node links[];
    boolean flag;
    Node(){
        this.links = new Node[26];
        this.flag = false;
    }
    public boolean containsKey(char ch){
        return links[ch-'a']!=null;
    }
    public void put(char ch,Node node){
        links[ch-'a'] = node;
    }
    public Node get(char ch){
        return links[ch-'a'];
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
    public void insert(String word){
        Node temp = this.root;
        for(char ch:word.toCharArray()){
            if(!temp.containsKey(ch))
                temp.put(ch,new Node());
            temp = temp.get(ch);
        }
        temp.setEnd();
    }
    public String search(String word){
        Node temp = this.root;
        String str = "";
        for(char ch:word.toCharArray()){
            if(temp.containsKey(ch)){
                 if(temp.isEnd()){
                    return str;
                }
                str = str+ch;
            }
            else{
                if(temp.isEnd())
                return str;
                else return "";
            }
            temp = temp.get(ch);
        }
        return str;
    }
}
class Solution {
    public String replaceWords(List<String> dictionary, String sentence) {
        Trie trie = new Trie();
        for(int i=0;i<dictionary.size();i++){
            trie.insert(dictionary.get(i));
        }
        String words[] = sentence.split(" ");
        String resSen = "";
        for(int i=0;i<words.length;i++){
            String res = trie.search(words[i]);
            if(res.isEmpty())
            resSen = resSen+words[i]+" ";
            else resSen = resSen+res+" ";
        }
        resSen = resSen.substring(0,resSen.length()-1);
        return resSen;
    }
}