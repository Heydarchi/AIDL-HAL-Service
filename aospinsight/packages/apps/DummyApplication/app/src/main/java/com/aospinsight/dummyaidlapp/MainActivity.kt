package com.aospinsight.dummyaidlapp

import android.os.Bundle
import com.google.android.material.snackbar.Snackbar
import androidx.appcompat.app.AppCompatActivity
import android.util.Log
import android.os.Environment

class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        Log.d("isExternalStorageReadOnly", " :" + isExternalStorageReadOnly())
        Log.d("isExternalStorageAvailable", " :" + isExternalStorageAvailable())

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
}