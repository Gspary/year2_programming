/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package audioduplex;

/**
 *
 * @author George
 */
public class AudioDuplex {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        
        AudioReciveThread receiver = new AudioReciveThread();
        AudioSendthread sender = new AudioSendthread();
        
        receiver.start();
        sender.start();
    }
    
}
