package com.example.myapplication;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.util.Log;
import android.widget.Toast;

public class MyBroadcastReceiver extends BroadcastReceiver {
    private static final String TAG = "MyBroadcastReceiver";


    @Override
//    public void onReceive(Context context, Intent intent) {
//        StringBuilder sb = new StringBuilder();
//        sb.append("Action: " + intent.getAction() + "\n");
//        sb.append("URI: " + intent.toUri(Intent.URI_INTENT_SCHEME).toString() + "\n");
//        String log = sb.toString();
//        Log.d(TAG, log);
//        Toast.makeText(context, log, Toast.LENGTH_LONG).show();
//    }
    public void onReceive(Context context, Intent intent) {

        switch (intent.getAction()) {
            case UsbService.ACTION_USB_PERMISSION_GRANTED: // USB PERMISSION GRANTED
                Toast.makeText(context, "USB Ready", Toast.LENGTH_SHORT).show();
                // display.setText("USB Ready");
                break;
            case UsbService.ACTION_USB_PERMISSION_NOT_GRANTED: // USB PERMISSION NOT GRANTED
                Toast.makeText(context, "USB Permission not granted", Toast.LENGTH_SHORT).show();
                //display.setText("USB ermission not gr");

                break;
            case UsbService.ACTION_NO_USB: // NO USB CONNECTED
                Toast.makeText(context, "No USB connected", Toast.LENGTH_SHORT).show();
                //display.setText("No USB connected");

                break;
            case UsbService.ACTION_USB_DISCONNECTED: // USB DISCONNECTED
                Toast.makeText(context, "USB disconnected", Toast.LENGTH_SHORT).show();
                //display.setText("USB disconnected");

                break;
            case UsbService.ACTION_USB_NOT_SUPPORTED: // USB NOT SUPPORTED
                Toast.makeText(context, "USB device not supported", Toast.LENGTH_SHORT).show();
                //display.setText("USB device not supporte");
                break;
            case UsbService.ACTION_USB_ATTACHED: // USB NOT SUPPORTED
                //Toast.makeText(context, "USB Attached", Toast.LENGTH_SHORT).show();
                //display.setText("USB device not supporte");
                break;
        }

    }
}