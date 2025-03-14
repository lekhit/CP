import java.io.*;
import java.util.*;

class MergeSort {
    int[] arr;
    int[] temp;
    int size;


void moveToTemp(int start, int end){
    for(int i=start;i<end;i++){
        temp[i]=arr[i];
    }
}
    void merge(int start, int mid, int end){
        int i=start,j=mid,index=start;
        //move first half to temp
        moveToTemp(start, mid);
        while(i<mid || j<end){
            if ((i < mid && j < end)) {
                if (arr[j] < temp[i]) {
                    arr[index] = arr[j++];
                } else {
                    arr[index] = temp[i++];
                }
            }
            else if(i<mid){
                arr[index] = temp[i++];
            }else{
                arr[index] = arr[j++]; // this should not be required
            }
            index++;
        }
    }
    /*
     * 2 5 6
     * 1 3 4
     * 
     * 1 2 3
     *  
     */

    void split(int start, int end){
        if(end-start <=1) return;
        int mid = (start+end)/2;
        split(start, mid);
        split(mid,end);
        merge(start, mid, end);
    }
    void sort(){
        split(0, size);
    }

    public int[] readInputFromFile(String fileName) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(fileName));
        int n = Integer.parseInt(br.readLine());
        size=n;
        arr = new int[n];
        temp = new int[n];
        
        String[] elements = br.readLine().split(" ");
        for(int i = 0; i < n; i++) {
            arr[i] = Integer.parseInt(elements[i]);
        }
        
        br.close();
        return arr;
    } 
    void writeOutputToFile(String fileName) throws IOException {
        BufferedWriter bw = new BufferedWriter(new FileWriter(fileName));
        for (int i = 0; i < size; i++) {
            bw.write(arr[i] + " ");
        }
        bw.close();
    }
    public static void main(String[] args) {
        MergeSort sorter = new MergeSort();
        try {
            sorter.readInputFromFile("/Users/lekhitborole/CP/CSES/sorting-and-searching/Collecting Numbers/input.txt");
            sorter.sort();
            sorter.writeOutputToFile("output.txt");
        } catch (IOException e) {
            System.out.println("Error reading file: " + e.getMessage());
        }
    }
}