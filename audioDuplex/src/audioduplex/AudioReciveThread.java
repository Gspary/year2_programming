/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package audioduplex;

import java.net.*;
import java.io.*;
import CMPC3M06.AudioPlayer;
import java.nio.ByteBuffer;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.sound.sampled.LineUnavailableException;
public class AudioReciveThread implements Runnable {
    static DatagramSocket receiving_socket;
    
    public void start(){
        Thread thread = new Thread(this);
	thread.start();
    }
    
    @Override
    public void run (){
     
        try{
            
            AudioPlayer player = new AudioPlayer();
            //***************************************************
            //Port to open socket on
            int PORT = 55555;
            //***************************************************
            
            //***************************************************
            //Open a socket to receive from on port PORT
            
            //DatagramSocket receiving_socket;
            try{
                receiving_socket = new DatagramSocket(PORT);
            } catch (SocketException e){
                System.out.println("ERROR: TextReceiver: Could not open UDP socket to receive from.");
                e.printStackTrace();
                System.exit(0);
            }
            //***************************************************
            
            //***************************************************
            //Main loop.
            byte[] buffer = new byte[512];
            boolean running = true;
            int key  = 15;
            while (running){
                
                try{
                    //Receive a DatagramPacket
                    
                    DatagramPacket packet = new DatagramPacket(buffer, 512);
                    
                    receiving_socket.receive(packet);
                    
                   //Decoding the encoded packets 
                   ByteBuffer unwrapDecrypt = ByteBuffer.allocate(buffer.length);
                    
                    ByteBuffer cipherText = ByteBuffer.wrap(buffer);
                    for(int j = 0; j < buffer.length/4; j++){
                        int fourByte = cipherText.getInt();
                        fourByte = fourByte ^ key; // XOR to decrypt
                        unwrapDecrypt.putInt(fourByte);
                    }
                    byte[] networkedBlock = unwrapDecrypt.array();
                    
                    
                    
                    
                    
                    
                    //plays the block
                    player.playBlock(networkedBlock);
                    
                    
                    
                }
                catch (IOException e){
                    System.out.println("ERROR: TextReceiver: Some random IO error occured!");
                    e.printStackTrace();
                }
            }
            //Close the socket
            receiving_socket.close();
            //***************************************************
            
        } catch (LineUnavailableException ex){
                Logger.getLogger(AudioReciveThread.class.getName()).log(Level.SEVERE, null, ex);
	}
        //***************************************************
    
    }
}
