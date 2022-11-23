#include "DummyImpl.h"

#include <android-base/logging.h>

namespace aidl {
namespace aospinsight {
namespace hardware {
namespace dummy_device {


ndk::ScopedAStatus DummyImpl::getPacketByCallback(const std::shared_ptr<IDummyCallback>& cb) {
   // LOG(INFO) << "dummy_device setting state for id=" << id << " to color " << std::hex << state.color;
  //      return ndk::ScopedAStatus::fromExceptionCode(EX_UNSUPPORTED_OPERATION);
    std::unique_lock<std::mutex> lock(dummyMutex);

    LOG(INFO) << "getPacketByCallback called!";


    if(cb==nullptr){
        return ndk::ScopedAStatus::fromExceptionCodeWithMessage(EX_NULL_POINTER, "Couldn't init the callback since the pointer is null!!");
    }

    if(dummyCallback==nullptr){
        dummyCallback = cb;
    }
    else{
        return ndk::ScopedAStatus::fromExceptionCodeWithMessage(EX_NULL_POINTER, "Re-initializing the callback is forbiden!!");
    }

    //Just to send invoke callback method
    DummyPacket dummyPacket;
    dummyPacket.id=202;
    dummyPacket.msg="A test message from the HAL service";
    onPacketEvent(&dummyPacket);
    
    
    return ndk::ScopedAStatus::ok();
   // }
}

ndk::ScopedAStatus DummyImpl::getPacket(DummyPacket* dummyPacket) {
    std::unique_lock<std::mutex> lock(dummyMutex);
    LOG(INFO) << "getPacket called!";
    return ndk::ScopedAStatus::ok();
}

void DummyImpl::onPacketEvent(DummyPacket* dummyPacket) {
    LOG(INFO) << "onNewPacket called!";
    dummyCallback->onGetPacket(*dummyPacket);
}

}  // namespace dummy_device
}  // namespace hardware
}  // namespace aospinsight
}  // namespace aidl
