package aospinsight.hardware.dummy_device;

@VintfStability
interface IDummyPlus{
    void getPacketByCallbackWithId(in aospinsight.hardware.dummy_device.IDummyCallback callback, in String uniquieId);

    void getPacketPlus(out aospinsight.hardware.dummy_device.DummyPacketPlus packet);

    void unregisterCallback(in String uniquieId);
}