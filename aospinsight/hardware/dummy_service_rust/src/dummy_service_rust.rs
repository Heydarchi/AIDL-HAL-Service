use aospinsight_hardware_dummy_device::aidl::aospinsight::hardware::dummy_device::IDummyPlus::IDummyPlus;
use aospinsight_hardware_dummy_device::aidl::aospinsight::hardware::dummy_device::IDummyPlus::BnDummyPlus;
use aospinsight_hardware_dummy_device::aidl::aospinsight::hardware::dummy_device::IDummyCallback::IDummyCallback;
use aospinsight_hardware_dummy_device::aidl::aospinsight::hardware::dummy_device::DummyPacketPlus::DummyPacketPlus;

use aospinsight_hardware_dummy_device::binder::{
    BinderFeatures, Interface, Result as BinderResult, Strong,
};

/*declare_binder_interface! {
    IDummyPlus["aospinsight.hardware.dummy_device.IDummyPlus/default/V2"] {
        native: DummyDevice,
        proxy: DummyDeviceProxy,
    }
}*/

pub struct DummyDevice;

impl Interface for DummyDevice {

}

impl IDummyPlus for DummyDevice {
    let mut p: *IDummyCallback;

    fn getPacketByCallbackWithId(&self, callback: &binder::Strong<dyn IDummyCallback>, unique_id: &str)  -> BinderResult<()> {
        let mut callbacks;// = self.callbacks.lock().unwrap();
        //callbacks.insert(unique_id.clone(), callback);

        // Generate the DummyPacketPlus
        let packet = DummyPacketPlus {
            /* fill packet with data */
            id:2,
            msg:"A message from dummy-server-rust",
            numbers : 40
        };

        // Call the registered callback with the generated packet
        if let Some(callbacks) = callbacks.get(&unique_id) {
            let _ = callback.onGetPacket(packet);
        }
        Ok(())

    }

    fn getPacketPlus(&self, data:&mut DummyPacketPlus) -> BinderResult<()>  {
        // Generate the DummyPacketPlus
        let packet = DummyPacketPlus {
            /* fill packet with data */
        };

        Ok(())
    }

    fn unregisterCallback(&self, unique_id: &str)  -> BinderResult<()> {
        let mut callbacks = self.callbacks.lock().unwrap();
        callbacks.remove(&unique_id);
        Ok(())
     }
}

pub fn main() {
    let my_service = DummyDevice;
    let my_service_binder = BnDummyPlus::new_binder(
        my_service,
        BinderFeatures::default(),
    );
    binder::add_service("dummy_service_rust", my_service_binder.as_binder())
        .expect("Failed to register service?");
    // Does not return - spawn or perform any work you mean to do before this call.
    binder::ProcessState::join_thread_pool()
}
