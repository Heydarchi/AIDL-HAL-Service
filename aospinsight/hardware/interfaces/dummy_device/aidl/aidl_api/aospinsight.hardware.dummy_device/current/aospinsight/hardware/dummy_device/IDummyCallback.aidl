package aospinsight.hardware.dummy_device;

@VintfStability
interface IDummyCallback{
    void onGetPacket(in aospinsight.hardware.dummy_device.DummyPacket packet);
}