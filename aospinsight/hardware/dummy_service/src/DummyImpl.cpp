#include "Dummy.h"

#include <android-base/logging.h>

namespace aidl {
namespace android {
namespace hardware {
namespace dummy_device {

static constexpr int kNumDefaultLights = 3;

ndk::ScopedAStatus Dummy::getPacketByCallback(const shared_prt<IDummyCallback>& cb) {
   // LOG(INFO) << "Lights setting state for id=" << id << " to color " << std::hex << state.color;
   /* if (id <= 0 || id > kNumDefaultLights) {
        return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
    } else {*/
    LOG(INFO) << "getPacketByCallback called!";
        return ndk::ScopedAStatus::ok();
   // }
}

ndk::ScopedAStatus Dummy::getPacket(std::shared_prt<DummyPacket>* dummyPacket) {
    LOG(INFO) << "getPacket called!";
    return ndk::ScopedAStatus::ok();
}

}  // namespace light
}  // namespace hardware
}  // namespace android
}  // namespace aidl