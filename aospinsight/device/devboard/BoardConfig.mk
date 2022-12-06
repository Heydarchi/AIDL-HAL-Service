
BOARD_SEPOLICY_DIRS += \
		vendor/aospinsight/device/devboard/sepolicy/vendor \
		vendor/aospinsight/device/devboard/sepolicy/service \
		vendor/aospinsight/device/devboard/sepolicy/hal \
		vendor/aospinsight/device/devboard/sepolicy/daemon \


########## Device Manifest & Framework Compatibility Matrix Manifest ##########

VENDOR_PATH = vendor/aospinsight

DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE += \
	$(VENDOR_PATH)/hardware/dummy_service/manifest/dummy_framework_compatibility_matrix.xml \
