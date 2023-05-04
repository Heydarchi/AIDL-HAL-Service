package aospinsight.hardware.dummy_device;

@VintfStability
parcelable DummyPacketPlus{
    int id;
    String msg;
    @nullable
    int[] numbers;
}