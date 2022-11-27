PRODUCT_PACKAGE_OVERLAYS := vendor/recop/device/recop_emulator/common/overlay

$(call inherit-product, device/generic/car/emulator/aosp_car_emulator.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/sdk_x86_64.mk)
#$(call inherit-product, vendor/recop/device/recop_emulator/device_recop_car.mk)

include vendor/aospinsight/device/devboard//BoardConfig.mk


EMULATOR_VENDOR_NO_SOUND := true
PRODUCT_NAME := aosp_car_x86_64
PRODUCT_DEVICE := generic_car_x86_64
PRODUCT_BRAND := AOSPInsight
PRODUCT_MODEL := AOSPInsight Car on x86_64 emulator

EMULATOR_VENDOR_NO_SENSORS := true



PRODUCT_PACKAGES += \
	dummy-service \
    GalleryReCop \
	DummyApp \
