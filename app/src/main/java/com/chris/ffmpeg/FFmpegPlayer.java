package com.chris.ffmpeg;

import android.util.Log;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import androidx.annotation.NonNull;

/**
 * 播放控制
 */
public class FFmpegPlayer implements SurfaceHolder.Callback {
    private static final String TAG = "FFmpegPlayer";
    private String mPath;
    private SurfaceHolder mSurfaceHolder;


    public FFmpegPlayer() {
    }


    /**
     * 设置播放地址
     *
     * @param path
     */
    protected void setDataPath(String path) {
        mPath = path;
        Log.i(TAG, "setDataPath : " + mPath);
    }

    protected void start() {
        startNative();
    }

    protected void stop() {
        stopNative();
    }

    protected void release() {
        releaseNative();
    }

    protected void prepare() {
        parpareNative(mPath);
    }

    protected void setSurfaceView(SurfaceView surfaceView) {
        Log.i(TAG, "setSurfaceView: ");
        if (mSurfaceHolder != null) {
            mSurfaceHolder.removeCallback(this);
        }
        if (surfaceView != null) {
            mSurfaceHolder = surfaceView.getHolder();
        }
    }


    @Override
    public void surfaceCreated(@NonNull SurfaceHolder holder) {
        Log.i(TAG, "surfaceCreated: ");

    }

    @Override
    public void surfaceChanged(@NonNull SurfaceHolder holder, int format, int width, int height) {
        Log.e(TAG, "surfaceChanged: ");
        setSurfaceViewNative(holder.getSurface());

    }

    @Override
    public void surfaceDestroyed(@NonNull SurfaceHolder holder) {
        Log.i(TAG, "surfaceDestroyed: ");
    }

    /**
     * native函数
     */
    private native void parpareNative(String data);

    private native void startNative();

    private native void stopNative();

    private native void releaseNative();

    private native void setSurfaceViewNative(Surface surface);

}
