package com.example.kinjal.foryou;

import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.support.v4.view.PagerAdapter;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.LinearLayout;

/**
 * Created by Kinjal on 20-01-2016.
 */
public class CustomSwipeAdapter extends PagerAdapter  implements View.OnClickListener {

    private int[] imageResources = {R.drawable.happy_piyu, R.drawable.sad_piyu, R.drawable.loving_piyu, R.drawable.missing_me_piyu};
    private Context ctx;
    private LayoutInflater layoutInflater;

    ImageView imageView;
    View item_view;

    public CustomSwipeAdapter(Context ctx)
    {
        this.ctx = ctx;
    }
    @Override
    public int getCount()
    {
        return imageResources.length;
    }

    @Override
    public boolean isViewFromObject(View view, Object object) {
        return (view == (LinearLayout)object);
    }

    @Override
    public Object instantiateItem(ViewGroup container, int position) {
        layoutInflater = (LayoutInflater)ctx.getSystemService(Context.LAYOUT_INFLATER_SERVICE);
        item_view = layoutInflater.inflate(R.layout.swipe_layout, container, false);
        imageView = (ImageView)item_view.findViewById(R.id.image_view);
        imageView.setImageResource(imageResources[position]);
        imageView.setId(position);
        imageView.setOnClickListener(this);
        container.addView(item_view);
        return item_view;
    }

    @Override
    public void destroyItem(ViewGroup container, int position, Object object) {
        container.removeView((LinearLayout)object);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId())
        {
            case 0:
                Intent happy;
                happy = new Intent(ctx, HappyMoments.class);
                ctx.startActivity(happy);
                break;

            case 1:
                Intent sad = new Intent(ctx, SadMoments.class);
                ctx.startActivity(sad);
                break;

            case 2:
                Intent lovely = new Intent(ctx, LovelyMoments.class);
                ctx.startActivity(lovely);
                break;

            case 3:
                Intent me = new Intent(ctx, MissingMe.class);
                ctx.startActivity(me);
                break;
        }
    }
}
