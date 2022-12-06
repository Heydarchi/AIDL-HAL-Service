
BOARD_VENDOR_SEPOLICY_DIRS += vendor/aospinsight/device/devboard/sepolicy/vendor 
BOARD_VENDOR_SEPOLICY_DIRS += vendor/aospinsight/device/devboard/sepolicy/hal 
BOARD_VENDOR_SEPOLICY_DIRS += vendor/aospinsight/device/devboard/sepolicy/service 
BOARD_VENDOR_SEPOLICY_DIRS += vendor/aospinsight/device/devboard/sepolicy/daemon 
BOARD_VENDOR_SEPOLICY_DIRS += vendor/aospinsight/device/devboard/sepolicy/app 


########## Device Manifest & Framework Compatibility Matrix Manifest ##########

VENDOR_PATH = vendor/aospinsight

DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE += \
	$(VENDOR_PATH)/hardware/dummy_service/manifest/dummy_framework_compatibility_matrix.xml \
