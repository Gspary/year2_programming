/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package audioduplex;

import java.net.*;
import java.io.*;

import CMPC3M06.AudioRecorder;
import java.nio.ByteBuffer;
import java.util.Vector;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.sound.sampled.LineUnavailableException;
public class AudioSendthread implements Runnable {
    static DatagramSocket sending_socket;
    
    public void start(){
        Thread thread = new Thread(this);
	thread.start();
    }
    
    public void run (){
     
         
        
	try {
            
            
            
            //Port to send to
            int PORT = 55555;
            //IP ADDRESS to send to
            InetAddress clientIP = null;
            try {
                clientIP = InetAddress.getByName("localhost");
            } catch (UnknownHostException e) {
                System.out.println("ERROR: TextSender: Could not find client IP");
                e.printStackTrace();
                System.exit(0);
            }
            //***************************************************
            
            //***************************************************
            //Open a socket to send from
            //We dont need to know its port number as we never send anything to it.
            //We need the try and catch block to make sure no errors occur.
            
            //DatagramSocket sending_socket;
            try{
                sending_socket = new DatagramSocket();
            } catch (SocketException e){
                System.out.println("ERROR: TextSender: Could not open UDP socket to send from.");
                e.printStackTrace();
                System.exit(0);
            }
            //***************************************************
            
            //***************************************************
            //Get a handle to the Standard Input (console) so we can read user input
            
            Vector<byte[]> voiceVector = new Vector<byte[]>();
            AudioRecorder recorder = new AudioRecorder();
            BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
            
            boolean running = true;
            int key = 15;
            while (running){
                try{
                    
                     byte[] buffer = recorder.getBlock();
                    
                    ByteBuffer unwrapEncrypt = ByteBuffer.allocate(buffer.length);
                    ByteBuffer plainText = ByteBuffer.wrap(buffer);
                    for( int j = 0; j < buffer.length/4; j++){
                        int fourByte = plainText.getInt();
                        fourByte = fourByte ^ key; // XOR operation with key
                        unwrapEncrypt.putInt(fourByte);
                        
                        }
                     byte[] encryptedBlock = unwrapEncrypt.array();
                    
                     
                     for(int l = 0; l<buffer.length/4; l++){
                         voiceVector.add(encryptedBlock);
                     }
                  
                    
                    
                    
                    
                   
                    
                    //Make a DatagramPacket from it, with client address and port number
                    DatagramPacket packet = new DatagramPacket(encryptedBlock, encryptedBlock.length, clientIP, PORT);
                    
                    //Send it
                    sending_socket.send(packet);
                    
                    
                    
                    
                } catch (IOException e){
                    System.out.println("ERROR: TextSender: Some random IO error occured!");
                    e.printStackTrace();
                }
            }
            //Close the socket
            sending_socket.close();
            //***************************************************
        } catch (LineUnavailableException ex) {
                Logger.getLogger(AudioSendthread.class.getName()).log(Level.SEVERE, null, ex);
	}
        //***************************************************
    }
}
