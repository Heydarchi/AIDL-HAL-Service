package aospinsight.hardware.dummy_device;

@VintfStability
interface IDummy{
    void getPacketByCallback(in aospinsight.hardware.dummy_device.IDummyCallback callback);

    void getPacket(out aospinsight.hardware.dummy_device.DummyPacket packet);
}