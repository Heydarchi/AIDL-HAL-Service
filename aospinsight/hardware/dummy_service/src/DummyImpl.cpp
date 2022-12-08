#include "DummyImpl.h"

#include <android-base/logging.h>

namespace aidl {
namespace aospinsight {
namespace hardware {
namespace dummy_device {


ndk::ScopedAStatus DummyImpl::getPacketByCallback(const std::shared_ptr<IDummyCallback>& cb) {
    std::unique_lock<std::mutex> lock(dummyMutex);

    LOG(INFO) << "getPacketByCallback called!";


    if(cb==nullptr){
        return ndk::ScopedAStatus::fromExceptionCodeWithMessage(EX_NULL_POINTER, "Couldn't init the callback since the pointer is null!!");
    }

    if(dummyCallback==nullptr){
        dummyCallback = cb;

        // LinkToDeath callback
        death_recipient_ = ::ndk::ScopedAIBinder_DeathRecipient(AIBinder_DeathRecipient_new(binderDiedCallbackAidl));
        binder_status_t linkRet =
                AIBinder_linkToDeath(dummyCallback->asBinder().get(), death_recipient_.get(), this);
        if (linkRet != ::STATUS_OK) {
            LOG(INFO) <<"!!!!  Cannot link to death: %d  !!!!" << linkRet;
            return ndk::ScopedAStatus::fromExceptionCodeWithMessage(EX_NULL_POINTER, "Couldn't link to death !!");
        }

    }
    else{
        return ndk::ScopedAStatus::fromExceptionCodeWithMessage(EX_NULL_POINTER, "Re-initializing the callback is forbiden!!");
    }

    LOG(INFO) << "The callback is registered successfully !";
    //Just to invoke a callback method
    DummyPacket dummyPacket;
    dummyPacket.id=202;
    dummyPacket.msg="A test message from the HAL service";
    onPacketEvent(&dummyPacket);
    
    return ndk::ScopedAStatus::ok();
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

void DummyImpl::binderDiedCallbackAidl(void* cookie_ptr) {
    auto dummyImpl = static_cast<DummyImpl*>(cookie_ptr);
    LOG(INFO) << "DummyApp died !!";
    dummyImpl->dummyCallback = nullptr;
}

}  // namespace dummy_device
}  // namespace hardware
}  // namespace aospinsight
}  // namespace aidl
