package com.aospinsight.dummyaidlapp

import android.os.Bundle
import com.google.android.material.snackbar.Snackbar
import androidx.appcompat.app.AppCompatActivity
import android.util.Log
import android.os.Environment
import android.os.Binder
import android.os.IBinder
import android.os.ServiceManager

import aospinsight.hardware.dummy_device.IDummy
import aospinsight.hardware.dummy_device.DummyPacket

class MainActivity : AppCompatActivity() {

    private var binder: IBinder? = null
    private lateinit var iDummy: IDummy
    private val idummyCallback = DummyCallbackImpl()

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        //Log.d(LOG, " :" + isExternalStorageReadOnly())
        //Log.d(LOG, " :" + isExternalStorageAvailable())

        //Init the interface and register the callback to the daemon
        getAidlInterface()
    }

    private fun isExternalStorageReadOnly(): Boolean {
        val extStorageState : String = Environment.getExternalStorageState();
        if (Environment.MEDIA_MOUNTED_READ_ONLY.equals(extStorageState)) {
            return true;
        }
        return false;
    }

    private fun isExternalStorageAvailable(): Boolean {
        val extStorageState : String = Environment.getExternalStorageState();
        if (Environment.MEDIA_MOUNTED.equals(extStorageState)) {
            return true;
        }
        return false;
    }

    private fun getAidlInterface(){
        binder = ServiceManager.getService(HAL_AIDL_SERVICE_NAME)
        binder?.let{
            iDummy = IDummy.Stub.asInterface(binder)
            Log.d(LOG, "DummyApp is bound to dummy_service")
            Log.d(LOG, "Register the callback by invoking getPacketByCallback from dummy-service")
            iDummy.getPacketByCallback(idummyCallback);
            Log.d(LOG, "Invoking getPacket from dummy-service")
            iDummy.getPacket(DummyPacket())
        }
    }

    companion object{
        val HAL_AIDL_SERVICE_NAME = "aospinsight.hardware.dummy_device.IDummy/default"
        val LOG = "DummyApp"
    }
}