package com.aospinsight.dummyaidlapp

import aospinsight.hardware.dummy_device.IDummyCallback
import aospinsight.hardware.dummy_device.DummyPacket
import android.util.Log

class DummyCallbackImpl : IDummyCallback.Stub() {

    override fun onGetPacket(dummyPacket : DummyPacket){
        Log.d(LOG, "A new DummyPacket received in onGetPacket !!!")
        Log.d(LOG, " id:" + dummyPacket.id)
        Log.d(LOG, " msg:" + dummyPacket.msg)

    }

    override fun getInterfaceVersion(): Int {
        return VESION
    }

    override fun getInterfaceHash(): String {
        return HASH
    }


    companion object{
        val LOG = "DummyCallbackImpl"
        val HASH = "2b11ca17996cfe44aaf8c7f58c618f443d7e389b"
        val VESION = 1
    }

}