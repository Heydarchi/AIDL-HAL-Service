PRODUCT_PACKAGE_OVERLAYS := vendor/recop/device/recop_emulator/common/overlay

$(call inherit-product, device/generic/car/emulator/aosp_car_emulator.mk)
$(call inherit-product, $(SRC_TARGET_DIR)/product/sdk_x86_64.mk)
#$(call inherit-product, vendor/recop/device/recop_emulator/device_recop_car.mk)


##### Specific BoardConfig #####
#VCC_FEATURES_BOARD_CONFIG_APPENDS += \
#    BoardConfig.mk \

EMULATOR_VENDOR_NO_SOUND := true
PRODUCT_NAME := aosp_car_x86_64
PRODUCT_DEVICE := generic_car_x86_64
PRODUCT_BRAND := AOSPInsight
PRODUCT_MODEL := AOSPInsight Car on x86_64 emulator

EMULATOR_VENDOR_NO_SENSORS := true

########## Device Manifest & Framework Compatibility Matrix Manifest ##########

VENDOR_PATH = vendor/aospinsight

DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE += \
	$(VENDOR_PATH)/hardware/dummy_service/manifest/dummy_framework_compatibility_matrix.xml \

#DEVICE_MANIFEST_FILE += \
#	$(VENDOR_PATH)/hardware/dummy_service/manifest/dummy_device_manifest.xml \

PRODUCT_PACKAGES += \
	dummy-service \
    GalleryReCop \
