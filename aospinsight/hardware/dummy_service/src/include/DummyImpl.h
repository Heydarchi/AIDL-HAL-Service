#pragma once

#include <aidl/aospinsight/hardware/dummy_device/BnDummy.h>
#include <mutex>

namespace aidl {
namespace aospinsight {
namespace hardware {
namespace dummy_device {

//package aospinsight.hardware.dummy_device;

//using aidl::aospinsight::hardware::dummy_device::BnDummy;
//using aidl::aospinsight::hardware::dummy_device::IDummyCallback;

class DummyImpl : public BnDummy {
    virtual ndk::ScopedAStatus getPacketByCallback(const std::shared_ptr<IDummyCallback>& cb) override;
    virtual ndk::ScopedAStatus getPacket(DummyPacket* dummyPacket) override;

protected:
    std::shared_ptr<IDummyCallback> dummyCallback = nullptr;
    std::mutex dummyMutex;

    void onPacketEvent(DummyPacket* dummyPacket);
};

}  // namespace dummy_device
}  // namespace hardware
}  // namespace aospinsight
}  // namespace aidl
