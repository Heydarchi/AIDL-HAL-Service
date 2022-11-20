#include "DummyImpl.h"

#include <android-base/logging.h>

namespace aidl {
namespace android {
namespace hardware {
namespace dummy_device {


ndk::ScopedAStatus Dummy::getPacketByCallback(const shared_prt<IDummyCallback>& cb) {
   // LOG(INFO) << "dummy_device setting state for id=" << id << " to color " << std::hex << state.color;
  //      return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
    LOG(INFO) << "getPacketByCallback called!";
        return ndk::ScopedAStatus::ok();
   // }
}

ndk::ScopedAStatus Dummy::getPacket(std::shared_prt<DummyPacket>* dummyPacket) {
    LOG(INFO) << "getPacket called!";
    return ndk::ScopedAStatus::ok();
}

}  // namespace dummy_device
}  // namespace hardware
}  // namespace android
}  // namespace aidl