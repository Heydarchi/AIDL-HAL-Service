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

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        Log.d("isExternalStorageReadOnly", " :" + isExternalStorageReadOnly())
        Log.d("isExternalStorageAvailable", " :" + isExternalStorageAvailable())
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
            iDummy?.let{
                Log.d(LOG, "DummyApp is bound to dummy_service")
                iDummy.getPacket(DummyPacket())
            }
        }
    }

    companion object{
        val HAL_AIDL_SERVICE_NAME = "aospinsight.hardware.dummy_device.IDummy/default"
        val LOG = "DummyApp"
    }
}