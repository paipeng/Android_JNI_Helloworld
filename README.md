# Android_JNI_Helloworld
A setup project with Android Studio for using NDK

## Generate C ++ header by using javah
cd projectPath/app/src/main

javah -d jni -cp pathTo/Library/Android/sdk/platforms/android-22/android.jar:../../build/intermediates/classes/debug/ com.paipeng.jnihelloworld.MainActivity

