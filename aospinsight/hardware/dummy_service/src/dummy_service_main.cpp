#include "DummyImpl.h"

#include <android-base/logging.h>
#include <android/binder_manager.h>
#include <android/binder_process.h>

using aidl::aospinsight::hardware::dummy_device::DummyImpl;

int main() {
    LOG(INFO) << "Dummy daemon started!";

    ABinderProcess_setThreadPoolMaxThreadCount(0);
    std::shared_ptr<DummyImpl> dummy = ndk::SharedRefBase::make<DummyImpl>();

    const std::string instance = std::string() + DummyImpl::descriptor + "/default";
    binder_status_t status = AServiceManager_addService(dummy->asBinder().get(), instance.c_str());
    CHECK_EQ(status, STATUS_OK);

    ABinderProcess_joinThreadPool();
    return EXIT_FAILURE;  // should not reached
}