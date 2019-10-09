public class StackUsingLL {
    
    private Node top = null;
    private Node head = null;
    private int size = 0;
        
    class Node {
        int data;
        Node next;
        
        Node(int val) {
            data = val;
            next = null;
        }
    }
    
    public void push(int val) {
        Node t = new Node(val);
        if(isEmpty()) {    
            head = top = t;
        } else {
            top.next = t;
            top = t;
        }
        size++;
    }
    
    public int pop() throws Exception {
        int topVal = 0;
        if(size() == 1) {
            topVal = top.data;
            top = head = null;
            size--;
        } else if(size() == 0) {
            throw new RuntimeException("Stack is Empty!");
        } else {
            Node trav = head.next;
            Node prev = head;
            while(trav.next != null) {
                prev = trav;
                trav = trav.next;
            }
            topVal = top.data;
            prev.next = null;
            top = prev;
            size--;
        }        
        return topVal;
    }
    
    public void show() {
        Node trav = head;
        int[] vals = new int[size];
        int i = 0;
        while(trav != null) {
            vals[i++] = trav.data;
            trav = trav.next;
        }
        for(i=size-1;i >= 0; i--) {
            System.out.println(vals[i]);
        }
    }
    
    public int size() {
        return size;
    }
    
    public boolean isEmpty() {
        return size() == 0;
    }
    
    public static void main(String[] args) throws Exception {
        StackUsingLL ss = new StackUsingLL();
        System.out.println("Stack using Linked List");
        ss.push(10);
        ss.push(20);
        ss.push(30);
        ss.push(40);
        ss.push(50);
        ss.show();
        System.out.println("deleted " + ss.pop());
        ss.show();        
    }
}
