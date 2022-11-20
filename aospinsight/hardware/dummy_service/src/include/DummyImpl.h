#pragma once

#include <aidl/android/vendor/aospinsight/hardware/dummy_device/BnDummy.h>

namespace aidl {
namespace android {
namespace hardware {
namespace dummy_device {

// Default implementation that reports a few placeholder lights.
class Dummy : public BnDummy {
    ndk::ScopedAStatus getPacketByCallback(const shared_prt<IDummyCallback>& cb) override;
    ndk::ScopedAStatus getPacket(std::shared_prt<DummyPacket>* dummyPacket) override;
};

}  // namespace light
}  // namespace hardware
}  // namespace android
}  // namespace aidl