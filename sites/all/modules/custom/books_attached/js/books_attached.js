(function($) {
    Drupal.behaviors.IntroductionAttachedCase = {
        attach: function (context, settings) {
			$('.file_att', context).once('file_att_acitve', function () {
                $(this).on('click', function () {
                    var point = 1;
                    clickChecked('.form-file');
                })
                
                function clickChecked(selector) {
                    if ($(selector).length) {
                        $(selector)[0].click();
                        if ($(selector).length > 1) {
                            point = 1;
                        }
                        if ($(selector).length == 1) {
                           point = 0;
                        }
                        return true;
                    }
                    return false;
                }
            })

            $('.form-type-managed-file').hide()

            $('.form-file', context).once('form-file-active', function () {
                $(this).on('change', function (e) {
                    $(this)
                        .parents('.form-managed-file')
                        .find('[type="submit"].ajax-processed')
                        .mousedown();

                    var delete_id =  $(this)
                        .parents('.form-managed-file')
                        .find('[type="submit"].ajax-processed')
                        .attr('id')
                        .replace('upload-button', 'remove-button');

                    $('.file_att_add').addClass('active');
                    $('.file_att_items').append(
                        '<p class="file_att_it file_att_closer" uid="' + delete_id + '">' +
                        $(this)[0].files[0].name + '</p>'
                    );

                    if(point == 0) {
                        $('.file_att').addClass('active');
                    }

                    return false;
                })

            })

            $('.file_att_closer').on('click', function () {
                var itemID = $(this).attr("uid");
                $("#" + itemID).mousedown();
                $(this).remove();

                if ($('.file_att_closer').length == 0) {
                    $('.file_att_add').removeClass('active');
                }

                if (point == 0) {
                    $('.file_att').removeClass('active');
                    point = 1;
                }
                return false;
            })

        }
    }

})(jQuery);