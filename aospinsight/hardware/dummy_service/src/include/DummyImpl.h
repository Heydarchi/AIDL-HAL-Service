#pragma once

#include <aidl/aospinsight/hardware/dummy_device/BnDummy.h>
#include <mutex>

namespace aidl {
namespace aospinsight {
namespace hardware {
namespace dummy_device {


class DummyImpl : public BnDummy {
    virtual ndk::ScopedAStatus getPacketByCallback(const std::shared_ptr<IDummyCallback>& cb) override;
    virtual ndk::ScopedAStatus getPacket(DummyPacket* dummyPacket) override;

protected:
    std::shared_ptr<IDummyCallback> dummyCallback = nullptr;
    std::mutex dummyMutex;

    ::ndk::ScopedAIBinder_DeathRecipient death_recipient_;
    static void binderDiedCallbackAidl(void* cookie_ptr);

    void onPacketEvent(DummyPacket* dummyPacket);
};

}  // namespace dummy_device
}  // namespace hardware
}  // namespace aospinsight
}  // namespace aidl
