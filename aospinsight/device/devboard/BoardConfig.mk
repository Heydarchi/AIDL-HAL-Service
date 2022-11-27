
BOARD_SEPOLICY_DIRS += \
        vendor/aospinsight/device/devboard/sepolicy/hal \
        vendor/aospinsight/device/devboard/sepolicy/vnd \
        vendor/aospinsight/device/devboard/sepolicy/app \

#BOARD_SEPOLICY_UNION += \
#        genfs_contexts \
#        file_contexts \
#        sepolicy.te

########## Device Manifest & Framework Compatibility Matrix Manifest ##########

VENDOR_PATH = vendor/aospinsight

DEVICE_FRAMEWORK_COMPATIBILITY_MATRIX_FILE += \
	$(VENDOR_PATH)/hardware/dummy_service/manifest/dummy_framework_compatibility_matrix.xml \

#DEVICE_MANIFEST_FILE += \
#	$(VENDOR_PATH)/hardware/dummy_service/manifest/dummy_device_manifest.xml \