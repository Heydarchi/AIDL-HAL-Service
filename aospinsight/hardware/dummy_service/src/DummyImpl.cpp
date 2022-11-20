#include "DummyImpl.h"

#include <android-base/logging.h>

namespace aidl {
namespace aospinsight {
namespace hardware {
namespace dummy_device {


ndk::ScopedAStatus DummyImpl::getPacketByCallback(const std::shared_ptr<IDummyCallback>& cb) {
   // LOG(INFO) << "dummy_device setting state for id=" << id << " to color " << std::hex << state.color;
  //      return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
    LOG(INFO) << "getPacketByCallback called!";
        return ndk::ScopedAStatus::ok();
   // }
}

ndk::ScopedAStatus DummyImpl::getPacket(DummyPacket* dummyPacket) {
    LOG(INFO) << "getPacket called!";
    return ndk::ScopedAStatus::ok();
}

}  // namespace dummy_device
}  // namespace hardware
}  // namespace aospinsight
}  // namespace aidl
